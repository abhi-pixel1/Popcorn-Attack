from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def index():
    f = open("chaubey.txt","w")
    f.write("chaubey")
    return render_template('index.html')


@app.route('/test')
def test():
    f = open("chaubey1.txt","w")
    f.write("chaubey1")
    return render_template('index.html')

if __name__ == "__main__":
    app.run()