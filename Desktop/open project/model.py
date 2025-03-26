import numpy as np
import torch
import tensorflow as tf
import cv2
from torchvision import transforms
from PIL import Image

def load_image(image_path) -> torch.Tensor:
      image_bgr = cv2.imread(image_path)  # Shape: (H, W, 3), dtype=uint8
      image_rgb = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2RGB)  # Convert to RGB
      transform = transforms.Compose([
            transforms.ToTensor(),  # Converts to [0, 1] and (C, H, W)
            transforms.Normalize(
                  mean=[0.485, 0.456, 0.406],  # ImageNet stats (RGB)
                  std=[0.229, 0.224, 0.225]
                  ) if "resnet" in backbone else lambda x: x  # Skip norm if not needed
            ])
      tensor = transform(image_rgb).unsqueeze(0)  # Add batch dim: (1, C, H, W)
      return tensor
    
    