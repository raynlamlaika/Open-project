document.getElementById('imageInput').addEventListener('change', function(event) {
      const file = event.target.files[0];
      const reader = new FileReader();
  
      reader.onload = function() {
          document.getElementById('uploadedImage').src = reader.result; // Base64 format
      };
      reader.readAsDataURL(file);
  });