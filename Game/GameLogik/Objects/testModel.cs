using GameLogik.Objects.Components;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameLogik.Objects
{
    public class testModel : Updatable, Renderable
    {
        float xPos, yPos, zPos;
        string FileLocation = "";
        public  testModel()
        {
            xPos = 0;
            yPos = 0;
            zPos = 0;
            FileLocation = @"test.txt";
        }
        public override void Update()
        {
            xPos += 0.01f;
        }
    }
}
