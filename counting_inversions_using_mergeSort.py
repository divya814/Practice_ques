# Counting no. of inversions, i.e, the no. of pairs where (arr[i]>arr[j]) and i<j using merge sort

def merge(arr,l,mid,r):
    n1=mid-l+1
    n2=r-mid
    a=[0]*n1
    b=[0]*n2
    for i in range(n1):
        a[i]=arr[l+i]
    for i in range(n2):
        b[i]=arr[mid+1+i]
    i,j,k=0,0,l
    inv=0
    while i<n1 and j<n2:
        if a[i]<=b[j]:
            arr[k]=a[i]
            i+=1
            k+=1
        else:
            arr[k]=b[j]
            inv+=n1-i  # inversion of all the remaining elements that are greater is counted,i.e, a[i+1],a[i+2]... >b[j] and i<j
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
    return inv 

def mergeSort(arr,l,r):
    inv=0
    if(l<r):
        mid=(l+r)//2
        inv+=mergeSort(arr,l,mid)
        inv+=mergeSort(arr,mid+1,r)
        inv+=merge(arr,l,mid,r)        
    return inv


arr=[3,2,1]
n=len(arr)
print(mergeSort(arr,0,n-1))

    
