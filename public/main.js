const IP = "http://localhost:3000"; // Сюда вставляем локальный IP компьютера на котором исполняется код
const users = document.querySelector(".users"); // Наша циферка в кружочке))

// Получаем количество посетителей
const interval = setInterval(() => {
  fetch(`${IP}/users`)
    .then((response) => response.json())
    .then((result) => {
      if (users.innerText != result) {
        users.innerText = result;
      }
    })
    .catch((error) => console.log("error", error));
}, 500);

// Тут мигаем датчиками на странице при пересечении их
const sensor = setInterval(() => {
  fetch(`${IP}/sensors`)
    .then((response) => response.json())
    .then((result) => {
      console.log(result);
      if (result === 1) {
        document.querySelectorAll(".circle1").forEach((e) => {
          e.style.backgroundColor = "red";
        });
      } else if (result === -1) {
        document.querySelectorAll(".circle2").forEach((e) => {
          e.style.backgroundColor = "red";
        });
      } else if (result === 0) {
        document.querySelectorAll(".circle2, .circle1").forEach((e) => {
          e.style.backgroundColor = "gray";
        });
      }
    })
    .catch((error) => console.log("error", error));
}, 100);
