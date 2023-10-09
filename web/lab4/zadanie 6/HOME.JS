window.onload = function () {
    // Восстановление сохраненных значений
    document.querySelector("#Age").value = localStorage.getItem("age");
    document.querySelector("#Height").value = localStorage.getItem("height");
    document.querySelector("#Weight").value = localStorage.getItem("weight");
}

document.querySelector(".btn").addEventListener("click", function () {
    var clickSound = new Audio("sounds/click-sound.wav");
    clickSound.play();

    const ageInput = document.querySelector("#Age");
    const ageValue = parseInt(ageInput.value);
    const additionalFields = document.getElementById('additionalFields');
    const additionalFields2 = document.getElementById('additionalFields2');
    const heightInput = document.querySelector("#Height");
    const weightInput = document.querySelector("#Weight");
    const bmiInput = document.querySelector("#bmi-result");
    // Сохранение значений в localStorage
    localStorage.setItem("age", ageInput.value);
    localStorage.setItem("height", heightInput.value);
    localStorage.setItem("weight", weightInput.value);
    let bmi;

    if (document.querySelector("#athlete-no").checked && ageValue >= 18 && ageValue <= 65) {
        const heightValue = heightInput.value / 100;
        const weightValue = weightInput.value;

        bmi = weightValue / (heightValue * heightValue);

        if (bmi < 16) {
            document.querySelector("#weight-condition").innerHTML = "Выраженный дефицит массы тела";
        } else if (bmi >= 16 && bmi < 18.5) {
            document.querySelector("#weight-condition").innerHTML = "Недостаточная масса тела";
        } else if (bmi >= 18.5 && bmi <= 25) {
            document.querySelector("#weight-condition").innerHTML = "Нормальная масса тела";
        } else {
            document.querySelector("#weight-condition").innerHTML = "Ожирение 3-ой степени";
        }
    } else {
        document.querySelector("#weight-condition").innerHTML = "Для мужчин и женщин старше 65 лет, подростков (до 18 лет), профессиональных спортсменов калькуляция индекса массы тела не может быть рассчитана по типовой формуле";
        bmi = "";
    }

    bmiInput.value = bmi;
});

document.querySelectorAll("input[name='athlete']").forEach(input => {
    input.addEventListener('change', () => {
        const ageInput = document.querySelector("#Age");
        const ageValue = parseInt(ageInput.value);
        const additionalFields = document.getElementById('additionalFields');
        const additionalFields2 = document.getElementById('additionalFields2');
        
        if (input.value === 'yes') {
            additionalFields.style.display = 'none';
            additionalFields2.style.display = 'block';
            ageInput.value = "";
        } else {
            if (ageValue !== '') {
                additionalFields.style.display = 'block';
                additionalFields2.style.display = 'none';
            }
        }
    });
});

document.querySelectorAll(".input").forEach(input => {
    input.addEventListener('input', () => {
        document.querySelector("#weight-condition").innerHTML = "";
        document.querySelector("#bmi-result").value = "";
    });
});

document.querySelector("#Age").addEventListener('input', function () {
    const ageValue = parseInt(document.querySelector("#Age").value);
    const additionalFields = document.getElementById('additionalFields');
    const additionalFields2 = document.getElementById('additionalFields2');
    
    if (ageValue < 18 || ageValue > 65) {
        additionalFields.style.display = 'none';
        additionalFields2.style.display = 'block';
    } else {
        additionalFields.style.display = 'block';
        additionalFields2.style.display = 'none';
    }
});
