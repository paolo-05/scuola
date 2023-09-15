const slider = document.getElementById('generating');
slider.addEventListener("input", function () {
    const sliderValue = slider.value;
    const displayValue = document.getElementById('generating-value');
    displayValue.value = sliderValue;
    localStorage.setItem('generating', sliderValue);
});