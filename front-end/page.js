document.addEventListener("DOMContentLoaded", () => {
    const imageInput = document.getElementById("imageInput");
    const uploadedImage = document.getElementById("uploadedImage"); // Corrected reference

    imageInput.addEventListener("change", function(event) {
        const file = event.target.files[0]; // Get the selected file

        if (file) {
            const reader = new FileReader(); // Create a FileReader to read the image

            reader.onload = function(e) {
                uploadedImage.src = e.target.result; // Set the image source
                uploadedImage.style.display = "block"; // Show the image
                console.log("Image file received:", file.name); // Log file name
            };

            reader.readAsDataURL(file); // Read file as a data URL
        }
    });
});

function applyModel() {
    const uploadedImage = document.getElementById("uploadedImage");

    if (uploadedImage.src) {
        console.log("Applying model to:", uploadedImage.src);
        alert("Model applied successfully! (Simulation)");
        // Here you can process the image further (e.g., send to a backend or apply an effect)
    } else {
        alert("Please upload an image first.");
    }
    print("model applied");
}
