class Solution{
    public static void  quicksort(int arr[],int l,int h)
	{
		int pivot=0;
		if(l<h)
		{
		pivot=partition(arr,l,h);
		quicksort(arr,l,pivot-1);
		quicksort(arr,pivot+1,h);
		
		}
		
	}
	public static void swap(int arr[],int a,int b)
	{
		int temp=0;
		temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
    public static int partition(int arr[],int l,int h)
	{
		int pivot=arr[h];
		int i=l-1,j=0;
		for(j=l;j<=h-1;j++)
		{
			if(arr[j]<pivot)
			{
				i++;
				swap(arr,i,j);
			}
		}
		swap(arr,i+1,h);
		return i+1;
	}
    public static int kthSmallest(int[] arr, int l, int r, int k) 
    {
        quicksort(arr,l,r);
        return arr[k-1];
    }
  
  public static void main(String[]args)
  {
    int arr[]={7,10,4,3,20,15};
    int n=arr.length; int k=3;
    Solution obj=new Solution();
    System.out.println(obj.kthsmallest(arr,0,n-1,k));
  }
  
}
