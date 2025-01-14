# Install

```bash
sudo apt install -y git python3-full python3-pip
sudo rm /usr/lib/python3.*/EXTERNALLY-MANAGED                           # not a nice thing
python3 -m pip install --user qmk
```

```bash
PATH=$PATH:$HOME/.local/bin
qmk setup
```


## Compile (Keyboard: ISO)

```bash
PATH=$PATH:$HOME/.local/bin
qmk compile -kb framework/numpad -km default
```


## Compile (NumPad)

```bash
PATH=$PATH:$HOME/.local/bin
qmk compile -kb framework/numpad -km default
```


## Flash (Keyboard: ISO)

```bash
PATH=$PATH:$HOME/.local/bin
qmk flash -kb framework/numpad -km default -c
```


## Flash (NumPad)

```bash
PATH=$PATH:$HOME/.local/bin
qmk flash -kb framework/numpad -km default -c
```
