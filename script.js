const scrollTopBtn = document.getElementById("scrollTopBtn");

// показати/сховати кнопку при скролі
window.addEventListener("scroll", () => {
  if (window.scrollY > 200) {
    // якщо прокрутили вниз більше ніж 200px
    scrollTopBtn.classList.add("show");
  } else {
    scrollTopBtn.classList.remove("show");
  }
});

// дія при натисканні
scrollTopBtn.addEventListener("click", () => {
  window.scrollTo({
    top: 0,
    behavior: "smooth", // плавне повернення
  });
});


// показ форм
const buyLink = document.querySelector('nav a[href="main.html"]');
const consultLink = document.querySelector('nav a[href="hp.html"]');

const formsSection = document.getElementById("formsSection");
const buyForm = document.getElementById("buyForm");
const consultForm = document.getElementById("consultForm");

buyLink.addEventListener("click", (e) => {
  e.preventDefault(); // блокуємо перехід на іншу сторінку
  formsSection.style.display = "block";
  buyForm.style.display = "block";
  consultForm.style.display = "none";
  window.scrollTo({ top: formsSection.offsetTop, behavior: "smooth" });
});

consultLink.addEventListener("click", (e) => {
  e.preventDefault();
  formsSection.style.display = "block";
  consultForm.style.display = "block";
  buyForm.style.display = "none";
  window.scrollTo({ top: formsSection.offsetTop, behavior: "smooth" });
});

