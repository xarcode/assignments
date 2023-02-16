const uname = 'xarcode'
const pass = '12345'

let login = () => {
    let username = document.querySelector('#username').value;
    let password = document.querySelector('#password').value;

    if(username.length == 0) alert('Please input username')
    if(password.length == 0) alert('Please input password')

    if(username != uname || password != pass)
        alert('Username or password does not match')
    else{
        let loginForm = document.querySelector('.login');
        loginForm.style.display = 'none';
    
        let result = document.querySelector('.result');
        result.style.display = 'block'
        result.innerHTML = `WELCOME ${username}`;
    }
    }