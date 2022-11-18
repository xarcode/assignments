# q1

initialize_df = function(x, y)
{
	df = data.frame(names=x, height=y)
}

to_meter = function(df)
{
	m = numeric(0)
	for(h in df$height){ m = c(m, h/100) }

	new_df = data.frame(names=df$names, height_in_m=m)
}

n = scan(what='')
h = scan()
people_cm = initialize_df(n, h)
people_cm
people_m = to_meter(people_cm)
people_m