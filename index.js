// Слушатель порта
const SerialPort = require("serialport");
const port = new SerialPort("COM3", {
  baudRate: 9600,
});

let users = 0;
let sensor = 0;

// Получаем данные из ардуины
port.on("data", (e) => {
  users = users + parseInt(e.toString("utf8")) >= 0 ? users + parseInt(e.toString("utf8")) : 0;
  if (parseInt(e.toString("utf8")) > 0) {
    sensor = 1;
  } else if (parseInt(e.toString("utf8")) < 0) {
    sensor = -1;
  } else if (parseInt(e.toString("utf8")) === 0) {
    sensor = 0;
  }
  console.log(users, e.toString("utf8"));
  console.log(sensor);
});

// Связь "бэкэнда" с фронтом
const bodyParser = require("body-parser");
const express = require("express");
const app = express();

app.use(express.static(__dirname + "/public"));
app.use(bodyParser.json());

app.get("/users", (_, res) => {
  res.json(users);
});

app.get("/sensors", (_, res) => {
  res.json(sensor);
});

app.listen(3000);
