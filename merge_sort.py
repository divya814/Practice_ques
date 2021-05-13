def merge(arr,l,mid,r):
    n1=mid-l+1
    n2=r-mid
    a=[0]*n1
    b=[0]*n2
    # breakdown into 2 separate lists
    for i in range(n1):
        a[i]=arr[l+i]
    for i in range(n2):
        b[i]=arr[mid+1+i]
    # merging
    i,j,k=0,0,l
    while i<n1 and j<n2:
        if a[i]<b[j]:
            arr[k]=a[i]
            i+=1
            k+=1
        else:
            arr[k]=b[j]
            j+=1
            k+=1
    while i<n1:
        arr[k]=a[i]
        i+=1
        k+=1
    while j<n2:
        arr[k]=b[j]
        j+=1
        k+=1
        

def mergeSort(arr,l,r):
    if(l<r):
        mid=(l+r)//2
        mergeSort(arr,l,mid)
        mergeSort(arr,mid+1,r)
        merge(arr,l,mid,r)
        

arr=[2,4,6,7,14,1]
n=len(arr)
mergeSort(arr,0,n-1)
for i in range(n):
    print(arr[i],end=" ")

    
