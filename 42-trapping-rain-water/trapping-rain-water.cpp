class Solution {
public:
    int trap(vector<int>& v) {
        stack<pair<int,int>>st,st2;
        int n=v.size();
        vector<pair<int,int>>vp(n);
        vector<pair<int,int>>vp2(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top().first<v[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                vp[i]={-1,-1};
            }
            else{
                vp[i]={st.top().first,st.top().second};
            }
            st.push({v[i],i});
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top().first<=v[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                vp2[i]={-1,-1};
            }
            else{
                vp2[i]={st.top().first,st.top().second};
            }
            st.push({v[i],i});
        }
        // for(int i=0;i<n;i++){
        //     cout<<vp[i].first<<" "<<vp[i].second <<endl;
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<vp2[i].first<<" "<<vp2[i].second<<endl;
        // }
        int ans=0;
        int mam=*max_element(v.begin(),v.end());
        int midx1=-1,midx2=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i]==mam)
            {
                midx1=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]==mam)
            {
                midx2=i;
                
            }
        }
        int sum=0;
        if(v[midx1]==v[midx2] and midx1!=midx2)
        {
            int a=v[midx1];
            
            for(int i=midx1;i<=midx2;i++)
            {
                sum+=abs(v[i]-a);

            }
            //return sum;
        }

        for(int i=0;i<n;i++)
        {
            if(i==midx1) break;
            int ng=vp[i].first;
            int idx=vp[i].second;
            if(idx==-1) continue ;
            if(idx==i+1) continue;
            int mim=min({ng,v[i]});
            i++;
            while(i<idx)
            {
                ans+=abs(v[i]-mim);
                i++;
            }
            
            i--;
        }
        cout<<ans<<endl;
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==midx2) break;
            int ng=vp2[i].first;
            int idx=vp2[i].second;
            if(idx==-1) continue ;
           if( idx==(i-1)) continue ;
            int mim=min({ng,v[i]});
            i--;
            while(i>idx)
            {
                ans+=abs(v[i]-mim);
                cout<<"hua h"<<endl;
                i--;
            }
            
            i++;
        }

        return (ans+sum);


        
    }
};