#include "SortedVectorDict.hpp"
void SortedVectorDict::insert(int value)
{

    //find the position
    auto findPos = lower_bound(data.begin(), data.end(),value);

    //then insert at the spot where it needs to go
    data.insert(findPos, value);
}
bool SortedVectorDict::lookup(int value) const
{
    //create the lowest and the highest based off of the vector
    int lowV = 0;
    int highV = data.size() - 1;

    //need to iterate through each item to compare and find the middle value

    while (lowV <= highV)
    {
        //divide the vector and create a middle variable
        int midVal = lowV + (highV - lowV)/2;

        //if found in the middle, process stops
        if (data[midVal] == value)
        {
            return true;
        }

        //now lets check if the value is greater than the left
        if (data[midVal] < value)
        {
            lowV = midVal + 1;
        }

        else
        {
            highV = midVal - 1;
        }
    }

    return false;
}
void SortedVectorDict::remove(int value)
{
    //find the element
    auto findVal = lower_bound(data.begin(), data.end(),value);

    //if the element isn't at the end we continue looping and checking the value
    if (findVal !=data.end() && *findVal == value)
    {
        data.erase(findVal);
    }

}