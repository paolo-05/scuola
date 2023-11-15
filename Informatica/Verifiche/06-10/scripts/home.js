const img = document.getElementById("img");
const description = document.getElementById("description");
const cols = document.querySelectorAll("div.col");

const imgArray = ["javascript", "budget", "frasi"];

for (let i = 0; i < cols.length; i++) {
  cols[i].addEventListener("mouseover", () => {
    img.src = `./imgs/${imgArray[i + 1]}.gif`;
    description.value = `Es${i + 1}: ${imgArray[i + 1]}`;
  });

  cols[i].addEventListener("mouseout", () => {
    img.src = `./imgs/${imgArray[0]}.gif`;
    description.value = "";
  });

  cols[i].addEventListener("click", () => {
    window.location = `./${imgArray[i + 1]}.html`;
  });
}
