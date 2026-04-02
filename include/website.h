#ifndef WEBSITE_H
#define WEBSITE_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const char* ssid = "D128c01h";
const char* password = "Dd0102Ch8";

const char* html = R"""(
  <!DOCTYPE html>
  <html lang="uk">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Smart Lock Control</title>
      <style>
          
          body {
              background-color: #1c1c1e; 
              font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif;
              display: flex;
              flex-direction: column;
              align-items: center;
              justify-content: center;
              height: 100vh;
              margin: 0;
              color: white;
          }

          h1 {
              font-weight: 300;
              margin-bottom: 10px;
          }

          
          .status-container {
              margin-bottom: 40px;
              text-align: center;
          }
          
          .status-icon {
              font-size: 80px;
              margin-bottom: 10px;
              transition: all 0.3s ease;
          }

          .status-text {
              font-size: 24px;
              font-weight: bold;
              letter-spacing: 1px;
          }

        
          .btn-container {
              display: flex;
              flex-direction: column;
              gap: 20px;
              width: 80%;
              max-width: 300px;
          }

          button {
              padding: 20px;
              font-size: 18px;
              border: none;
              border-radius: 16px;
              cursor: pointer;
              font-weight: 600;
              transition: transform 0.1s, opacity 0.2s;
              box-shadow: 0 4px 15px rgba(0,0,0,0.3);
          }

          button:active {
              transform: scale(0.96); 
          }

          .btn-open {
              background: linear-gradient(135deg, #34c759, #30b350); 
              color: white;
          }

          .btn-close {
              background: linear-gradient(135deg, #ff3b30, #e0332a); 
              color: white;
          }

          
          .locked { color: #ff3b30; }
          .unlocked { color: #34c759; }

      </style>
  </head>
  <body>

      <h1>Smart Lock Control</h1>

      <div class="status-container">
          <div id="icon" class="status-icon locked">🔒</div>
          <div id="text" class="status-text">ЗАЧИНЕНО</div>
      </div>

      <div class="btn-container">
          <button class="btn-open" onclick="sendCommand('open')">ВІДКРИТИ</button>
          <button class="btn-close" onclick="sendCommand('close')">ЗАКРИТИ</button>
      </div>

      <script>
        
          
          function sendCommand(action) {
              const icon = document.getElementById('icon');
              const text = document.getElementById('text');

              console.log("Натиснуто кнопку: " + action);

              
              if (action === 'open') {
                  icon.innerText = '🔓';
                  icon.className = 'status-icon unlocked';
                  text.innerText = 'ВІДЧИНЕНО';
                  text.style.color = '#34c759';
              } else {
                  icon.innerText = '🔒';
                  icon.className = 'status-icon locked';
                  text.innerText = 'ЗАЧИНЕНО';
                  text.style.color = '#ff3b30';
              }

              
              
              fetch("/" + action)
              .then(response => {
                  console.log("Сервер відповів OK");
              })
              .catch(error => {
                  
                  console.log("Запит відправлено (імітація), сервер поки недоступний.");
              });
          }
      </script>

  </body>
  </html>
)""";

#endif