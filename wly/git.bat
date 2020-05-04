cd ..
git checkout master
git branch -D wly
git pull upstream master
git checkout -b wly

git status

git add .
git commit -m "%date% - wly"
git push origin wly