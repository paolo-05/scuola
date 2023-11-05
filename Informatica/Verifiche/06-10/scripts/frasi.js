const inputs = document.querySelectorAll("input[type=text]");
const genera = document.getElementById("genera");
const cancella = document.getElementById("cancella");

const list = document.getElementById("list");

document.addEventListener("DOMContentLoaded", () => {
  for (let i = 0; i < inputs.length; i++) {
    const savedValue = window.localStorage.getItem(inputs[i].id);
    if (savedValue) {
      inputs[i].value = savedValue;
    }
  }
});

for (let i = 0; i < inputs.length; i++) {
  inputs[i].addEventListener("input", () => {
    window.localStorage.setItem(inputs[i].id, inputs[i].value);
  });
}

for (let i = 0; i < inputs.length; i++) {
  inputs[i].addEventListener("input", () => {
    window.localStorage.setItem(`${inputs[i].id}`, `${inputs[i].value}`);
  });
}

genera.addEventListener("click", () => {
  const soggettiInput = document.getElementById("soggetti").value.split(", ");
  const verbiInput = document.getElementById("verbi").value.split(", ");
  const oggettiInput = document.getElementById("oggetti").value.split(", ");

  if (
    soggettiInput.length === 0 ||
    verbiInput.length === 0 ||
    oggettiInput.length === 0
  ) {
    alert("Inserisci almeno un soggetto, un verbo e un complemento oggetto.");
    return;
  }

  const randomSoggetto =
    soggettiInput[Math.floor(Math.random() * soggettiInput.length)];
  const randomVerbo = verbiInput[Math.floor(Math.random() * verbiInput.length)];
  const randomOggetto =
    oggettiInput[Math.floor(Math.random() * oggettiInput.length)];

  const sentence = `${randomSoggetto} ${randomVerbo} ${randomOggetto}`;

  const sentenceElement = document.createElement("p");
  sentenceElement.textContent = sentence;
  list.appendChild(sentenceElement);
});

cancella.addEventListener("click", () => {
  const sentences = list.querySelectorAll("p");
  if (sentences.length > 0) {
    const lastSentence = sentences[sentences.length - 1];
    list.removeChild(lastSentence);
  }
});
