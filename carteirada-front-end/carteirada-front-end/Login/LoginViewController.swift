//
//  LoginViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 23/09/22.
//

import UIKit

class LoginViewController: UIViewController {

    @IBOutlet weak var loginButtonEddit: UIButton!
    
    @IBOutlet weak var emailTF: UITextField!
    @IBOutlet weak var pwTF: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupButton()
    }
    @IBAction func registerButton(_ sender: Any) {
        self.dismiss(animated: false, completion: nil)
    }
    

    private func setupButton() {
        loginButtonEddit.layer.cornerRadius = 20
        loginButtonEddit.layer.shadowColor = UIColor.black.cgColor
        loginButtonEddit.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        loginButtonEddit.layer.shadowRadius = 4.0
        loginButtonEddit.layer.shadowOpacity = 0.5
        loginButtonEddit.layer.masksToBounds = false
    }

    @IBAction func loginButton(_ sender: Any) {
        
    }
}
