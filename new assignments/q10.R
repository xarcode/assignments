# q10

a = 0
b = 0

for(i in 1:3)
{
	a = a + 1
	for(j in 1:4)
	{
		b = b + 1
		if(j == 2)
		{
			break
		}
		print(paste('a = ',a))
		print(paste('b = ',b))
	}
}