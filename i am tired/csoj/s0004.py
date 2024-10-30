a=input()
str=input()
list1=str.split(" ")
list2 = list(set(list1))
z=0
list3 = list2
for x in list2:
  for y in list1:
    if x == y:
      list3[z]=int(list3[z])+1
  z+=1
f = 0
for i in range(z):
  if list3[i]>list3[f]:
    f=i
print(list2[f])
print(list2)
  