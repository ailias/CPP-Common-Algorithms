//
// Created by Ailias on 2017/3/7.
//

/*
 * insertSort():insertion sort function.
 * the sorted result is the original array.
 * 精髓是：发现比自己大的就往后挪一位，最终退出内循环（前提条件是前面的都是排好序的）的是不大于自己的索引，
 * 所以该索引+1就是自己需要保存的位置。
 * @param inArray array which need to be sorted.
 * @param inSize  array size
 */
template<class T>
void insertSort(T *inArray, unsigned int inSize) {
    for (unsigned int arrIndex = 1; arrIndex < inSize; ++arrIndex) {
        T currentElement = inArray[arrIndex];//暂存当前需要排序的元素
        unsigned int sortedIndex = arrIndex - 1;//只处理在当前元素之前的元素的索引
        for (; sortedIndex >= 0 && inArray[sortedIndex] > currentElement; --sortedIndex) {
            //all element that bigger than currentElement should be move back to one step.
            //所有比currentElement大的元素都会向后移动一位（最多只会覆盖currentElement位置的元素）
            inArray[sortedIndex + 1] = inArray[sortedIndex];
        }
        //the final sortedIndex is the end of the sorted array part index.
        //this means all elements whose index not bigger than sortedIndex are sorted,
        //and the spare index sortedIndex+1 will be replaced by currentElement
        //此时的sortedIndex表示的是已经排好序的且不大于currentElement的索引，
        //sortedIndex是前面后移后空出来的位置，正好放上currentElement。
        inArray[sortedIndex + 1] = currentElement;
    }
}
