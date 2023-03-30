let display = document.getElementById("display");
let buttons = Array.from(document.getElementsByClassName("button"));
buttons.map((button) => {
  button.addEventListener("click", (e) => {
    switch (e.target.innerText) {
      case "C":
        display.innerText = "0";
        break;
      case "=":
        try {
          display.innerText = eval(display.innerText);
        } catch {
          display.innerText = "Error";
        }
        break;
      case "←":
        if (display.innerText) {
          display.innerText = display.innerText.slice(0, -1);
        }
        break;
      default:
        console.log(e.target.innerText);
        if (display.innerText == "0") display.innerText = e.target.innerText;
        else {
          if (e.target.innerText == "×") display.innerText += "*";
          else display.innerText += e.target.innerText;
        }
    }
  });
});
