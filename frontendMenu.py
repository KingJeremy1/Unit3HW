import tkinter as tk

def on_click():
    label.config(text="Button clicked!")

def submit():
    # Get the value from the input field
    user_ID = entry.get()
    label.config(text=f"Hello, {user_ID}!")
    amount = entry2.get()
    label2.config(text=f"Hello, {amount}!")
    selected_option = var.get()
    label3.config(text=f"You selected: {selected_option}")


# Create the main window
root = tk.Tk()
root.title("Bank App")

# ClientID label
label = tk.Label(root, text="Enter Client ID")
label.pack(padx=20, pady=10)

entry = tk.Entry(root) 
entry.pack(padx=10, pady=5)

# Option picker

label3 = tk.Label(root, text="Choose one option:")
label3.pack(padx=10, pady=5)

var = tk.IntVar() # var to hold chosen option
var.set(1)  

radio1 = tk.Radiobutton(root, text="Deposit", variable=var, value=1)
radio2 = tk.Radiobutton(root, text="Withdraw", variable=var, value=2)

radio1.pack(padx=10, pady=2)
radio2.pack(padx=10, pady=2)

# Amount Label
label2 = tk.Label(root, text="How much money?")
label2.pack(padx=20, pady=10)

entry2 = tk.Entry(root) 
entry2.pack(padx=10, pady=5)



# Create a submit button
button = tk.Button(root, text="Submit", command=submit)
button.pack(padx=10, pady=10)

# Run the application
root.mainloop()