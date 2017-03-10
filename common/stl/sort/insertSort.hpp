//
// Created by Ailias on 2017/3/7.
//

/*
 * insertSort():insertion sort function.
 * the sorted result is the original array.
 * @param inArray array which need to be sorted.
 * @param inSize  array size
 */
template<class T>
void insertSort(T *inArray, unsigned int inSize) {
    for (unsigned int arrIndex = 1; arrIndex < inSize; ++arrIndex) {
        T splitElement = inArray[arrIndex];
        unsigned int sortedIndex = arrIndex - 1;
        for (; sortedIndex >= 0 && inArray[sortedIndex] > splitElement; --sortedIndex) {
            //all element that bigger than splitElement should be move back to one step.
            //所有比splitElement大的元素都会向后移动一位（最多只会覆盖splitElement位置的元素）
            inArray[sortedIndex + 1] = inArray[sortedIndex];
        }
        //the final sortedIndex is the end of the sorted array part index.
        //this means all elements whose index not bigger than sortedIndex are sorted,
        //and the spare index sortedIndex+1 will be replaced by splitElement
        //此时的sortedIndex表示的是已经排好序的且不大于splitElement的索引，
        //sortedIndex是前面后移后空出来的位置，正好放上splitElement。
        inArray[sortedIndex + 1] = splitElement;
    }
}
