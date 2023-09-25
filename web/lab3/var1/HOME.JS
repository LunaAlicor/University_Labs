document.querySelector(".btn").addEventListener("click", function () {
    var clickSound = new Audio("sounds/click-sound.wav");
    clickSound.play();

    const heightValue = document.querySelector("#Height").value / 100;
    const weightValue = document.querySelector("#Weight").value;
    const ageValue = parseInt(document.querySelector("#Age").value);

    const bmiinput = document.querySelector("#bmi-result");
    let bmi;

    if ((document.querySelector("#athlete-no").checked && ageValue >= 18 && ageValue <= 65)) {
        bmi = weightValue / (heightValue * heightValue);

        if (bmi < 16) {
            document.querySelector("#weight-condition").innerHTML = "Выраженный дефицит массы тела";
        } else if (bmi >= 16 && bmi < 18.5) {
            document.querySelector("#weight-condition").innerHTML = "Недостаточная масса тела";
        } else if (bmi >= 18.5 && bmi <= 25) {
            document.querySelector("#weight-condition").innerHTML = "Нормальная масса тела";
        } else if (bmi > 25 && bmi <= 30) {
            document.querySelector("#weight-condition").innerHTML = "Избыточная масса тела (предожирение)";
        } else if (bmi > 30 && bmi <= 35) {
            document.querySelector("#weight-condition").innerHTML = "Ожирение 1-ой степени";
        } else if (bmi > 35 && bmi <= 40) {
            document.querySelector("#weight-condition").innerHTML = "Ожирение 2-ой степени";
        } else{
            document.querySelector("#weight-condition").innerHTML = "Ожирение 3-ой степени";
        }
    } else {
        document.querySelector("#weight-condition").innerHTML = "Для мужчин и женщин старше 65 лет, подростков (до 18 лет), профессиональных спортсменов калькуляция индекса массы тела не может быть рассчитана по типовой формуле";
        bmi = "";
    }

    bmiinput.value = bmi;
});
