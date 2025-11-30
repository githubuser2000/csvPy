#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
from PIL import Image, ImageDraw, ImageFont

def text_to_hd_image(text_file, image_file):
    # --- Einstellungen ---
    img_width, img_height = 1920, 1080  # HD-Auflösung
    bg_color = (255, 255, 255)          # Hintergrund weiß
    text_color = (0, 0, 0)              # Schrift schwarz
    font_size = 30                       # Schriftgröße
    thickness = 2                        # leicht dicke Kanten

    # --- Text laden ---
    with open(text_file, "r", encoding="utf-8") as f:
        text = f.read().strip()

    # --- Bild erstellen ---
    img = Image.new("RGB", (img_width, img_height), bg_color)
    draw = ImageDraw.Draw(img)

    # --- Schriftart laden ---
    font = ImageFont.truetype("/usr/share/fonts/truetype/msttcorefonts/Arial.ttf", font_size)

    # --- Textgröße berechnen ---
    text_width, text_height = draw.textsize(text, font=font)
    x = (img_width - text_width) // 2
    y = (img_height - text_height) // 2

    # --- Text mit leicht dicken Rändern zeichnen ---
    for dx in range(-thickness, thickness+1):
        for dy in range(-thickness, thickness+1):
            draw.text((x+dx, y+dy), text, font=font, fill=text_color)

    # --- Bild speichern ---
    img.save(image_file)
    print(f"Bild erstellt: {image_file}")

# --- Ausführen mit Übergabeparametern ---
if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Verwendung: python text_to_image.py textdatei.txt bilddatei.png")
        sys.exit(1)
    
    text_file = sys.argv[1]
    image_file = sys.argv[2]
    text_to_hd_image(text_file, image_file)

