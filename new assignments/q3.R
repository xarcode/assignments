# q3

mat = matrix(runif(100, 0, 1), 10, 10)
mat

# (i)
rmean = rowMeans(mat)
print('row means are')
print(rmean)
print('column means are')
cmean = colMeans(mat)
print(cmean)

# (ii)
sum = sum(diag(mat))
print(paste('sum of diagonals', sum))

# (iii)
print(paste('standard deviation is', sd(mat)))