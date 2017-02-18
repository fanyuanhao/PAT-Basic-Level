/***
*qsort.c - quicksort algorithm; qsort() library function for sorting arrays
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       To implement the qsort() routine for sorting arrays.
*
*****************************************************************************

**/

#include <cruntime.h>
#include <stdlib.h>
#include <search.h>
#include <internal.h>

/* 加快运行速度的优化选项 */
#pragma optimize("t", on)

/* 函数原型*/
static void __cdecl shortsort(char *lo, char *hi, size_t width,
                int (__cdecl *comp)(const void *, const void *));
static void __cdecl swap(char *p, char *q, size_t width);

/* this parameter defines the cutoff between using quick sort and
   insertion sort for arrays; arrays with lengths shorter or equal to the
   below value use insertion sort */

/* 这个参数定义的作用是，当快速排序的循环中遇到大小小于CUTOFF的数组时，就使用插入
排序来进行排序，这样就避免了对小数组继续拆分而带来的额外开销。这里的取值8，是
经过测试以后能够时快速排序算法达到最快的CUTOFF的值。*/

#define CUTOFF 8            /* testing shows that this is good value */

 
/* 源代码中这里是qsort的代码，但是我觉得先解释了qsort要调用的函数的功能比较

好。

    shortsort函数：

    这个函数的作用，上面已经有提到。就是当对快速排序递归调用的时候，如果遇到
大小小于CUTOFF的数组，就调用这个函数来进行排序，而不是继续拆分数组进入下一层
递归。因为虽然这里用的是基本排序方法，它的运行时间和O(n^2)成比例，但是如果是
只有8个元素，它的速度比需要递归的快速排序要快得多。另外，在源代码的注释中，说
这是一个插入排序(insertion sort)，但是我觉得这个应该是一个选择排序才对
(selection sort)。至于为什么用选择排序而不用插入排序，应该是和选择排序的元素
交换次数少有关系，只需要N-1次交换，而插入排序平均需要(N^2)/2次。之所以要选择
交换次数少的算法，是因为有可能数组里面的单个元素的大小很大，使得交换成为最主
要的性能瓶颈。

参数说明：

char *lo;    指向要排序的子数组的第一个元素的指针
char *hi;    指向要排序的子数组的最后一个元素的指针
size_t width;  数组中单个元素的大小
int (__cdecl *comp)(const void *,const void *);   用来比较两个元素大
小的函数指针，这个函数是你在调用qsort的时候传入的参数，当前一个指针指向的元素
小于后一个时，返回负数；当相等时，返回0；当大于时，返回正数。*/

//选择排序 
static void __cdecl shortsort (
    char *lo,
    char *hi,
    size_t width,
    int (__cdecl *comp)(const void *, const void *)
    )
{
    char *p, *max;
    /* Note: in assertions below, i and j are alway inside original bound of array to sort. */
    while (hi > lo) {
        max = lo;
      /*下面这个for循环作用是从lo到hi的元素中，选出最大的一个，max指针指向这个最大项*/
        for (p = lo+width; p <= hi; p += width) {
            if (comp(p, max) > 0) {
                max = p;
            }
        }
      /*这里把最大项和hi指向的项向交换*/
        swap(max, hi, width);
       /*hi向前移动一个指针。经过这一步，在hi后面的是已经排好序的比未排序部分所有的数要大的数。*/
        hi -= width;
    }
}

 

/*下面分析swap函数：
这个函数比较简单，就是交换两个项的操作，不过是用指针来实现的。
*/

static void __cdecl swap (
    char *a,
    char *b,
    size_t width
    )
{
    char tmp;
    if ( a != b )
        /* Do the swap one character at a time to avoid potential alignment
           problems. */
        while ( width-- ) {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
        }
}

 

/*下面是最重要的部分，qsort函数：*/
/*使用的是非递归方式，所以这里有一个自定义的栈式结构，下面这个定义是栈的大小
*/

#define STKSIZ (8*sizeof(void*) - 2)

void __cdecl qsort (
    void *base,
    size_t num,
    size_t width,
    int (__cdecl *comp)(const void *, const void *)
    )
{
   /*由于使用了某些技巧（下面会讲到），使得栈大小的需求不会大于1+log2(num)，因此30的栈大小应该是足够了。为什么说是30呢？
   其实在上面STKSIZ的定义中可以计算出sizeof(void*)＝4，所以8*4-2＝30*/
    char *lo, *hi;              /* ends of sub-array currently sorting   数组的两端项指针，用来指明数组的上界和下界*/
    char *mid;                  /* points to middle of subarray  数组的中间项指针*/
    char *loguy, *higuy;        /* traveling pointers for partition step  循环中的游动指针*/
    size_t size;                /* size of the sub-array  数组的大小*/
    char *lostk[STKSIZ], *histk[STKSIZ];
    int stkptr;                 /* stack for saving sub-array to be processed  栈顶指针*/

/*如果只有一个或以下的元素，则退出*/
    if (num < 2 || width == 0)
        return;                 /* nothing to do */
        
    stkptr = 0;                 /* initialize stack */

    lo = base;
    hi = (char *)base + width * (num-1);        /* initialize limits */

    /*这个标签是伪递归的开始*/
recurse:

    size = (hi - lo) / width + 1;        /* number of el's to sort */
   /*当size小于CUTOFF时，使用选择排序算法更快*/
    if (size <= CUTOFF) {
        shortsort(lo, hi, width, comp);
    }
    else {
      /*首先我们要选择一个分区项。算法的高效性要求我们找到一个近似数组中间值
的项，但我们要保证能够很快找到它。我们选择数组的第一项、中间项和最后一项的中
间值，来避免最坏情况下的低效率。测试表明，选择三个数的中间值，比单纯选择数组
的中间项的效率要高。

       我们解释一下为什么要避免最坏情况和怎样避免。在最坏情况下，快速排序算法
的运行时间复杂度是O(n^2)。这种情况的一个例子是已经排序的文件。如果我们选择最
后一个项作为划分项，也就是已排序数组中的最大项，我们分区的结果是分成了一个大
小为N-1的数组和一个大小为1的数组，这样的话，我们需要的比较次数是N + N-1 + N-2 
+ N-3 +...+2+1=(N+1)N/2=O(n^2)。而如果选择前 中 后三个数的中间值，这种最坏情况的
数组也能够得到很好的处理。*/

        mid = lo + (size / 2) * width;      /* find middle element */
       /*第一项 中间项 和最后项三个元素排序*/

        /* Sort the first, middle, last elements into order */
        if (comp(lo, mid) > 0) {
            swap(lo, mid, width);
        }
        if (comp(lo, hi) > 0) {
            swap(lo, hi, width);
        }
        if (comp(mid, hi) > 0) {
            swap(mid, hi, width);
        }

 /*下面要把数组分区成三块，一块是小于分区项的，一块是等于分区项的，而另一块是大于分区项的。*/
/*这里初始化的loguy 和 higuy两个指针，是在循环中用于移动来指示需要交换的两个元素的。
higuy递减，loguy递增，所以下面的for循环总是可以终止。*/

        loguy = lo; /* traveling pointers for partition step  循环中的游动指针*/
        higuy = hi; /* traveling pointers for partition step  循环中的游动指针*/

        /* Note that higuy decreases and loguy increases on every iteration,
           so loop must terminate. */
        for (;;) {
           /*开始移动loguy指针，直到A[loguy]>A[mid]*/
            if (mid > loguy) {
                do  {
                    loguy += width;
                } while (loguy < mid && comp(loguy, mid) <= 0);
            }

            /*如果移动到loguy>=mid的时候，就继续向后移动，使得A[loguy]>a[mid]。
            这一步实际上作用就是使得移动完loguy之后，loguy指针之前的元素都是不大于划分值的元素。*/
            if (mid <= loguy) {
                do  {
                    loguy += width;
                } while (loguy <= hi && comp(loguy, mid) <= 0);
            }

           /*执行到这里的时候，loguy指针之前的项都比A[mid]要小或者等于它*/
           
            /*下面移动higuy指针，直到A[higuy]<＝A[mid]*/
            do  {
                higuy -= width;
            } while (higuy > mid && comp(higuy, mid) > 0);

           /*如果两个指针交叉了，则退出循环。*/

            if (higuy < loguy)
                break;

            /* 此时A[loguy]>A[mid],A[higuy]<=A[mid],loguy<=hi，higuy>lo。*/
           /*交换两个指针指向的元素*/
            swap(loguy, higuy, width);

            /* If the partition element was moved, follow it.  Only need
               to check for mid == higuy, since before the swap,
               A[loguy] > A[mid] implies loguy != mid. */

           /*如果划分元素的位置移动了，我们要跟踪它。

              因为在前面对loguy处理的两个循环中的第二个循环已经保证了loguy>mid,

             即loguy指针不和mid指针相等。

             所以我们只需要看一下higuy指针是否等于mid指针，

            如果原来是mid==higuy成立了，那么经过刚才的交换，中间值项已经到了

loguy指向的位置（注意：刚才是值交换了，但是并没有交换指针。当higuy和mid相等，交换higuy和loguy指向的内容，higuy依然等于mid），所以让mid＝loguy，重新跟踪中间值。*/

            if (mid == higuy)
                mid = loguy;

            /* A[loguy] <= A[mid], A[higuy] > A[mid]; so condition at top
               of loop is re-established */

            /*这个循环一直进行到两个指针交叉为止*/
        }

        /*     A[i] <= A[mid] for lo <= i < loguy,
               A[i] > A[mid] for higuy < i < hi,
               A[hi] >= A[mid]
               higuy < loguy
           implying:
               higuy == loguy-1
               or higuy == hi - 1, loguy == hi + 1, A[hi] == A[mid] */

       /*上一个循环结束之后，因为还没有执行loguy指针和higuy指针内容的交换，所以loguy指针的前面的数组元素都不大于划分值，而higuy指针之后的数组元素都大于划分值，所以此时有两种情况：

       1)  higuy＝loguy－1

       2)  higuy＝hi－1，loguy＝hi+1

       其中第二种情况发生在一开始选择三个元素的时候，hi指向的元素和mid指向的元素值相等，而hi前面的元素全部都不大于划分值，使得移动loguy指针的时候，一直移动到了hi+1才停止，再移动higuy指针的时候，higuy指针移动一步就停止了，停在hi－1处。

       */

        /* Find adjacent elements equal to the partition element.  The
           doubled loop is to avoid calling comp(mid,mid), since some
           existing comparison funcs don't work when passed the same value
           for both pointers. */

        higuy += width;
        if (mid < higuy) {
            do  {
                higuy -= width;
            } while (higuy > mid && comp(higuy, mid) == 0);
        }
        if (mid >= higuy) {
            do  {
                higuy -= width;
            } while (higuy > lo && comp(higuy, mid) == 0);
        }

        /* OK, now we have the following:
              higuy < loguy
              lo <= higuy <= hi
              A[i]  <= A[mid] for lo <= i <= higuy
              A[i]  == A[mid] for higuy < i < loguy
              A[i]  >  A[mid] for loguy <= i < hi
              A[hi] >= A[mid] */

   /* We've finished the partition, now we want to sort the subarrays
           [lo, higuy] and [loguy, hi].
           We do the smaller one first to minimize stack usage.
           We only sort arrays of length 2 or more.*/

       /*
         我们可以想像一下，对于一个已经排序的数组，如果每次分成N-1和1的数组，
        而我们又每次都先处理N-1那一半，那么我们的递归深度就是和N成比例，这样对于大N，栈空间的开销是很大的。
        如果先处理1的那一半，栈里面最多只有2项。当划分元素刚好在数组中间时，栈的长度是logN。
         对于栈的操作，就是先把大的数组信息入栈。
       */

        if ( higuy - lo >= hi - loguy ) {
            if (lo < higuy) {
                lostk[stkptr] = lo;
                histk[stkptr] = higuy;
                ++stkptr;
            }                           /* save big recursion for later */

            if (loguy < hi) {
                lo = loguy;
                goto recurse;           /* do small recursion */
            }
        }
        else {
            if (loguy < hi) {
                lostk[stkptr] = loguy;
                histk[stkptr] = hi;
                ++stkptr;               /* save big recursion for later */
            }

            if (lo < higuy) {
                hi = higuy;
                goto recurse;           /* do small recursion */
            }
        }
    }

    /* We have sorted the array, except for any pending sorts on the stack.
       Check if there are any, and do them. */

   /*出栈操作，直到栈为空，退出循环*/

    --stkptr;
    if (stkptr >= 0) {
        lo = lostk[stkptr];
        hi = histk[stkptr];
        goto recurse;           /* pop subarray from stack */
    }
    else
        return;                 /* all subarrays done */
}


