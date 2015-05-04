/*
 * =====================================================================================
 *
 *       Filename:  2-2.cpp
 *
 *    Description:  bitmap海量数据的快速查找和去重
 *
 *        Version:  1.0
 *        Created:  2015年03月25日 18时59分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sherlock-coding
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
/* 
 * 现在我们来看如果内存要求是10MB呢？
 * 这当然不能用bitmap来直接计算。因为从40亿数据找出一个不存在的数据，我们可以将这么多的数据分成许
 *
 * 多块， 比如每一个块的大小是1000，那么第一块保存的就是0到999的数，第2块保存的就是1000 到1999的数……
 *
 * 实际上我们并不保存这些数，而是给每一个块设置一个计数器。 这样每读入一个数，我们就在它所在的块对应的计数器加1。
 *
 * 处理结束之后， 我们找到一个块，它的计数器值小于块大小(1000)， 说明了这一段里面一定有数字是文件中所不包含的。然后我们单独处理
 * 这个块即可。接下来我们就可以用Bit Map算法了。我们再遍历一遍数据， 把落在这个块的数对应的位置1(我们要先把这个数
 * 归约到0到blocksize之间)。 最后我们找到这个块中第一个为0的位，其对应的数就是一个没有出现在该文件中的数。)*/

const int N = 10000;
const int block_size = 1000;
int bucket[1+N/block_size] = {0};
int bitmap[1+block_size/32] = {0};

// 设置计数器的值
void setBucket(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        ++bucket[a[i]/block_size];
    }
}

// 判断每个块是否已满
void testFull(int a[], int n)
{
    for (int i=0; i <=N/block_size; ++i) {
        // 如果未满，则设置bitmap
        if (bucket[i] < block_size) {
            int start = i*block_size;
            int end = start + block_size;
            for ( int j=0; j<n; ++j) {
                if(a[j] >=start && a[j]<end) {
                    int tmp = a[j] - start;
                    bitmap[tmp/32] |= (1<<(tmp%32));
                }
            }

            // 找出不存在的数
            for( int j=0; j <= block_size/32; ++j) {
                for (int k=0; k < 32; ++k) {
                    if((bitmap[j] & (1<<k)) == 0) {
                        std::cout << start+j*32+k << std::endl;
                    }
                }
            }
        }
    }
}

int main()
{
    int a[] = {1, 2 ,3 ,4 , 6};

    setBucket(a, 5);
    testFull(a,5);

    return 0;
}
