# middle element must be less than the element present after and before it

a=[1,3,4,7,5,6,2]
n=len(a)
for i in range(1,n,2):
    if a[i]>a[i-1]:
        a[i],a[i-1]=a[i-1],a[i]   # Swap
        
    if a[i]>a[i+1] and i<=n-2:
        a[i],a[i+1]=a[i+1],a[i]   # Swap
        
print(a)
