# q5
X = c(TRUE, FALSE, FALSE, TRUE)
Y = c(FALSE, TRUE, FALSE, TRUE)

# (i)
print('element wise and of x and y')
X & Y
print('element wise or of x and y')
X | Y

# (ii)
a = X[0]
for(i in X) a = a && i

print(paste('Logical AND of X: ', a))

a = X[0]
for(i in X) a = a || i

print(paste('Logical OR of X: ', a))

a = Y[0]
for(i in Y) a = a && i

print(paste('Logical AND of Y: ', a))

a = Y[0]
for(i in Y) a = a || i

print(paste('Logical OR of Y: ', a))