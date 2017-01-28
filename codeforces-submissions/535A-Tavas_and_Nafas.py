def words(n):
   if n==0:
      return 'zero'
   elif n==1:
      return 'one'
   elif n==2:
      return 'two'
   elif n==3:
      return 'three'
   elif n==4:
      return 'four'
   elif n==5:
      return 'five'
   elif n==6:
      return 'six'
   elif n==7:
      return 'seven'
   elif n==8:
      return 'eight'
   else:
      return 'nine'
s=(raw_input())
n=int(s)
options={1:'ten',
             2:'twenty',
             3:'thirty',
             4:'forty',
             5:'fifty',
             6:'sixty',
             7:'seventy',
             8:'eighty',
             9:'ninety',
}
new={11:'eleven',
          12:'twelve',
          13:'thirteen',
          14:'fourteen',
          15:'fifteen',
          16:'sixteen',
          17:'seventeen',
          18:'eighteen',
          19:'nineteen'
}
if len(s)==1:
    s=words(n)
else:
    if n/10==1 and n%10!=0:
       s=new[n]
    elif n%10!=0:
         k=n%10
         n/=10
         s=options[n]+"-"+words(k)
    else:
        n/=10
        s=options[n]
print s
