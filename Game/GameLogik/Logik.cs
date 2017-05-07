using EngineWrapper;
using System;
using System.Collections.ObjectModel;
using System.Threading;

namespace GameLogik
{
    public class Logik
    {
        public EngineWrapperClass eng;

        public ObservableCollection<Updatable> allObjects;
        public Logik(EngineWrapperClass eng)
        {
            this.eng = eng;
        }

        public void AddNewObject(Updatable o)
        {
            allObjects.Add(o);
            eng.AddObject(o.)
        }


        public void UpdateAll()
        {
            foreach (var item in allObjects)
            {
                item.Update();
            }
        }

    }
}
