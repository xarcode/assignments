# q2

rainfall_amt = scan()
print(paste("mean is ", mean(rainfall_amt)))
print(paste('standard deviation is ', sd(rainfall_amt)))

highest = max(rainfall_amt)
lowest = min(rainfall_amt)

for(i in 1:length(rainfall_amt))
{
	if(rainfall_amt[i] == highest){ print(paste("highest rainfall amount recieved in day", (i)))}
	if(rainfall_amt[i] == lowest){ print(paste("lowest rainfall amount recieved in day", (i)))}
}