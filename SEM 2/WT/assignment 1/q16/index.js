(tbody = document.getElementsByTagName("tbody")[0]),
  (dataDiv = document.getElementsByClassName("text")[0]);

var data = prompt("Enter some lines:");
dataDiv.textContent = `You entered: ${data}`;
const arr = data.split(" ");
var dict = [];
arr.forEach((element) => {
  if (element != "") {
    x = dict.find((o) => o[0] == element);
    if (x) {
      x[1] += 1;
    } else {
      var arr2 = [element, 1];
      dict.push(arr2);
    }
  }
});

dict.forEach((row) => {
  tr = document.createElement("tr");
  td1 = document.createElement("td");
  td1.textContent = row[0];
  td2 = document.createElement("td");
  td2.textContent = row[0].length;
  td3 = document.createElement("td3");
  td3.textContent = row[1];
  tr.appendChild(td1);
  tr.appendChild(td2);
  tr.appendChild(td3);
  tbody.appendChild(tr);
});
