# q9

n = scan()
s = 0.0

for(i in 1:n)
{
	if(i < n)
	{
		cat('1/', i, ' + ')
		s = s + 1/i
	}
	if(i == n)
	{
		cat('1/', i)
		s = s + 1/i
	}
}

cat('sum ', s)
