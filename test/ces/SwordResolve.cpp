class public SwordResolve
{
    public int _swordResolve;//剑意

    public bool _draw;//是否拔刀

    private float _waiTime//距离上次获得经过了多长时间。

    public void change()//拔刀直接调用
    {
        _swordResolve = 0;
        _draw = true;
    }
    public void ResetWaitTime()
    {
        _waiTime = 0;
    }

    public void Update()
    {
        _waitime += Time.deteltime;
        if (_waiTime > 1  && _draw)
        {
            _swordResolve -= 5*Time.deteltime;
        }
        if (_waiTime > 0.5  && !_draw)
        {
            _swordResolve += 10*Time.deteltime;
        }
    }
    
}