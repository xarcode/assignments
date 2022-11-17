# q7

amt = c(90, 50, 100, 40, 20, 38)
chem = c('c1', 'c2', 'c3', 'c4', 'c5', 'c6')

pie(amt, label=chem, col=rainbow(length(amt)), init.angle=180)