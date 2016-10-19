using UnityEngine;
using System.Collections.Generic;
using LitJson;
using System.Text;

public class Client : MonoBehaviour {
    [System.Serializable]
    class Buff
    {
        public int id;
        public string description;
        public double baseAttack;
        public bool canRepeat;
    }
    [System.Serializable]
    class PlayerInfo
    {
        public int id;
        public string name;
        public List<Buff> buffList;
    }

	// Use this for initialization
	void Start () {
        Init();
	}

    void Init()
    {
        PlayerInfo playerInfo = new PlayerInfo
        {
            id = 1001,
            name = "lfwu",
            buffList = new List<Buff>
            {
                new Buff
                {
                    id = 1001001,
                    description = "this buff can reduce speed",
                    baseAttack = 20.0,
                    canRepeat = false
                },
                new Buff
                {
                    id = 1001002,
                    description = "this buff can increase physic attack",
                    baseAttack = 0,
                    canRepeat = true
                }
            }
        };

        string litJsonStr = string.Empty;
        string unityJsonStr = string.Empty;


        System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
        int count = 1000;


        sw.Start();
        for(var i = 0; i < count; ++i)
        {
            litJsonStr = JsonMapper.ToJson(playerInfo);
        }
        Debug.Log("LitJson Serialize use time:" + sw.ElapsedMilliseconds);


        sw.Reset();
        sw.Start();
        for(var i = 0; i < count; ++i)
        {
            unityJsonStr = JsonUtility.ToJson(playerInfo);
        }
        Debug.Log("UnityJson Serialize use time:" + sw.ElapsedMilliseconds);

        sw.Reset();
        sw.Start();
        for(var i = 0; i < count; ++i)
        {
            PlayerInfo litPlayerInfo = JsonMapper.ToObject<PlayerInfo>(litJsonStr);
        }
        Debug.Log("LitJson Deserialzie use time:" + sw.ElapsedMilliseconds);

        sw.Reset();
        sw.Start();

        for(var i = 0; i < count; ++i)
        {
            PlayerInfo unityJsonInfo = JsonUtility.FromJson<PlayerInfo>(litJsonStr);
        }
        Debug.Log("UnityJson Deserialize use time:" + sw.ElapsedMilliseconds);

        Debug.Log("unity string len:" + unityJsonStr.Length + ", litjson string len:" + litJsonStr.Length);
    }
}
