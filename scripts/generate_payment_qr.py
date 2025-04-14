import qrcode
from PIL import Image

def generate_payment_qr():
    print("Generating payment QR code...")
    try:
        # อ่านข้อมูลจากไฟล์ cart.txt
        with open("cart.txt", "r") as file:
            data = file.read()

        # สร้าง QR Code
        qr = qrcode.make(data)
        qr.save("payment_qr.png")
        print("QR code saved as payment_qr.png!")

        # แสดง QR Code
        qr.show()  # ใช้คำสั่งนี้เพื่อแสดงภาพใน default image viewer ของระบบ
    except FileNotFoundError:
        print("Error: cart.txt not found.")

if __name__ == "__main__":
    generate_payment_qr()