from Practice_event.inotify import FileEvent

def main():
    f = FileEvent()
    print(f.get_path())

main()