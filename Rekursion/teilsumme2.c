





bool teile(int arr[], int length, int pos, int p1, int p2)
{
    if (pos == length)
        return p1 == p2;
    return teile(arr, length, pos+1, p1 + arr[pos], p2) || 
           teile(arr, length, pos+1, p1, p2 + arr[pos]); 
}