const btnCalcola = document.getElementById('btn-calcola');
const btnAzzera = document.getElementById('btn-azzera');

const costi = [16, 25, 350, 200];
const qts = document.querySelectorAll('input[type="number"]');
const tots = document.querySelectorAll('input[type="text"]');

for (let i = 0; i < qts.length; i++) {
    qts[i].addEventListener("input", function () {
        const qt = parseInt(qts[i].value) || 0;
        tots[i].value = `${qt * costi[i]}€`;
    });
}

btnAzzera.addEventListener('click', function() {
    for (let i = 0; i < qts.length; i++) {
        qts[i].value = '';
        tots[i].value = '';
    }
    tots[4].value = '';
});

btnCalcola.addEventListener('click', function() {
    let sum = 0;
    for (let i = 0; i < qts.length; i++) {
        sum += parseInt(tots[i].value.slice(0, -1)) || 0;
    }
    tots[4].value = `${sum}€`;
});
