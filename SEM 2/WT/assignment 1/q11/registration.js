function validate() {
  let full_name = document.querySelector("#name").value;
  let email = document.querySelector("#email").value;
  let phone = document.querySelector("#phone").value;
  let username = document.querySelector("#username").value;
  let password = document.querySelector("#password").value;

  const nameRegex = /^[a-zA-Z]+ [a-zA-Z]+$/;
  if (nameRegex.test(full_name) == false) alert("Invalid name");
  const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
  if (emailRegex.test(email) === false) alert("invalid email");
  const phoneRegex = /^[6-9]\d{9}$/;
  if (phoneRegex.test(phone) === false) alert("Invalid phone number");
  const usernameRegex = /^[a-zA-Z0-9]+([._]?[a-zA-Z0-9]+)*$/;
  if (usernameRegex.test(username) === false) alert("Invalid username");
  const passwordRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{8,}$/;
  if (passwordRegex.test(password) === false) alert("Invalid password");

  const checkboxes = document.querySelectorAll("input[type=checkbox]");
  const checkboxLength = checkboxes.length;

  function isChecked() {
    for (let i = 0; i < checkboxLength; i++) {
      if (checkboxes[i].checked) return true;
    }

    return false;
  }

  if(isChecked() === false) alert('Please select atleast one language')
}
