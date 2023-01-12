# q11

sid = c(1,2, 3, 4, 5, 6)
age = c(22, 23, 22, 21, 21, 24)
pointer = c(8, 9, 8, 7, 6, 8)
dept = c('mca', 'mca', 'mca', 'mca', 'mca', 'mca')

student_df = data.frame(sid, age, pointer, dept)

student_df[2, 3] = 6.6

student_df[student_df == 'mca'] = 'cse'
student_df