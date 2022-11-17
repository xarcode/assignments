P = scan(what='')
I = c(10000, 14000, 24000, 43000, 12323, 13414, 43212, 36000)

low_risk = character(0)
high_risk = character(0)

for(i in 1:length(I))
{
	if(I[i] < 30000){ high_risk = c(high_risk, P[i])}
	else { low_risk = c(low_risk, P[i]) }
}

print('High risk people')
high_risk
print('Low risk people')
low_risk