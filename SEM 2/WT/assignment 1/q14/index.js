tbody = document.getElementsByTagName("tbody")[0];

for (let x = 0; x <= 10; x++) {
  tr = document.createElement("tr");
  td1 = document.createElement("td");
  td1.textContent = x;
  tr.appendChild(td1);
  td2 = document.createElement("td");
  td2.textContent = Math.pow(x, 2);
  tr.appendChild(td2);
  td3 = document.createElement("td");
  td3.textContent = Math.pow(x, 3);
  tr.appendChild(td3);
  tbody.appendChild(tr);
}
