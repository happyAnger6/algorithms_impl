def three_sum(a, target):
   s_a = sorted(a)
   n = len(a)
   res = []
   for i in range(n):
      if i >= 1 and a[i] == a[i-1]:
         continue
      left = target - a[i]
      l, r = i+1, n-1
      while l < r:
         if a[l] + a[r] == left:
            res.append((i, l, r))
            while l < r and a[l] == a[l+1]:
               l+=1
            while r > l and a[r-1] == a[r]:
               r-=1
            l+=1
            r-=1
         elif a[l] + a[r] > left:
            r-=1
         else:
            l+=1
   return res

if __name__ == "__main__":
   a = [1, -1, 2, -2, 4, 3, 3]
   print(three_sum(a, 3))


