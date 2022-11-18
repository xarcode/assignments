# q12

data(cars)
head(cars, 10)
a = cars
boxplot(a, main='Relation between Speed and Distance', xlab='Speed', ylab='Distance')
hist(a$speed, main='Relation between Speed and Distance', xlab='Speed', ylab='Distance')
