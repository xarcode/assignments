let employees = []

function grossPay(employee){
    if(employee.hours <= 40) return employee.hours * employee.rate

    return 40 * employee.rate + (employee.hours - 40) * employee.rate * 1.5
}

function calculate(){
    let name = prompt('Enter name of Employee')
    let hours = parseInt(prompt('Enter hours worked by employee'))
    let rate = parseFloat(prompt('Enter the hourly rate of employee'))

    employee = {
        name: name,
        hours: hours,
        rate: rate
    }

    employees.push(employee)
    display_details()
}

function display_details(){
    let newEmpIndex = employees.length - 1;
    let newEmpPaymentDetails = `<p>${employees[newEmpIndex].name} is paid &#8377;${grossPay(employees[newEmpIndex])} for working ${employees[newEmpIndex].hours} hours</p>`
    document.querySelector('#results').innerHTML += newEmpPaymentDetails;
}