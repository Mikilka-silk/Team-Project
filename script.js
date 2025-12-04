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
